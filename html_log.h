///<------------------------------------------------------------------------------
//< @file:   html_log.h
//< @author: 洪坤安
//< @date:   2016年3月19日
//< @brief:
//< Copyright (c) 2016 game. All rights reserved.
///<------------------------------------------------------------------------------

#ifndef _html_log_h_
#define _html_log_h_

#include <string>
#include <vector>

namespace cxxcleantool
{
	static const char* cn_file							= "文件";
	static const char* cn_folder						= "文件夹";
	static const char* cn_project						= "工程";
	static const char* cn_clean							= "清理#{beclean}的日志";
	static const char* cn_project_text					= "允许清理的c++文件列表以及待分析的c++源文件列表";
	static const char* cn_project_allow_files			= "允许清理的c++文件列表（不属于该列表的c++文件不允许被改动）";
	static const char* cn_project_allow_file			= "允许清理的文件 = %s";
	static const char* cn_project_source_list			= "待分析的c++源文件列表（不属于该列表的c++文件不会被分析）";
	static const char* cn_project_source				= "待分析的c++源文件 = %s";
	static const char* cn_project_allow_dir				= "允许清理文件夹";
	static const char* cn_line_old_text					= "该行原来的内容 = ";

	static const char* cn_parsing_file					= "分析%s文件的日志";
	static const char* cn_file_count_unused				= "共有%s个文件有多余的#include";
	static const char* cn_file_unused_count				= "文件%s中有%s行多余的#include";
	static const char* cn_file_unused_line				= "可移除第%s行";
	static const char* cn_file_unused_include			= "原来的#include文本 = %s";

	static const char* cn_file_count_can_replace		= "共有%s个文件可以替换#include";
	static const char* cn_file_can_replace_num			= "文件%s中可以有%s个#include可被替换";
	static const char* cn_file_can_replace_line			= "第%s行可以被替换";
	static const char* cn_file_replace_same_text		= "可以被替换为 = %s";
	static const char* cn_file_replace_old_text			= "原本的#include = %s";
	static const char* cn_file_replace_new_text			= "根据路径搜索得出的新的#include = %s";
	static const char* cn_file_force_include_text		= " ==>  [注意: 本次替换将被跳过，因为该行可能已被强制包含]";
	static const char* cn_file_replace_in_file			= "位于%s文件的%s行";

	static const char* cn_file_count_add_forward		= "共有%s个文件可以新增前置声明";
	static const char* cn_file_add_forward_num			= "文件%s中可以新增%s个前置声明";
	static const char* cn_file_add_forward_line			= "可在第%s行新增前置声明";
	static const char* cn_file_add_forward_old_text		= "该行原来的内容 = %s";
	static const char* cn_file_add_forward_new_text		= "新增前置声明 = %s";

	static const char* cn_project_history_title			= "本次清理结果";
	static const char* cn_project_history_clean_count	= "清理结果：共有%s个c++文件可被清理";
	static const char* cn_project_history_src_count		= "项目内共有%s个cpp（或cxx、cc）源文件";

	struct DivGrid
	{
		std::string text;
		int width;
	};

	struct DivRow
	{
		DivRow()
			: tabCount(0)
		{
		}

		int						tabCount;
		std::vector<DivGrid>	grids;
	};

	struct HtmlDiv
	{
		void Clear()
		{
			titles.clear();
			rows.clear();
		}

		void AddTitle(const char* title, int width = 100);

		void AddRow(const char* text, int tabCount = 1, int width = 100, bool needEscape = false);

		void AddGrid(const char* text, int width, bool needEscape = false);

		void AddTitle(const std::string &title, int width = 100)
		{
			AddTitle(title.c_str(), width);
		}

		void AddGrid(const std::string &text, int width, bool needEscape = false)
		{
			AddGrid(text.c_str(), width, needEscape);
		}

		void AddRow(const std::string &text, int tabCount = 1 /* 缩进tab数 */, int width = 100, bool needEscape = false)
		{
			AddRow(text.c_str(), tabCount, width, needEscape);
		}

		std::vector<DivGrid>	titles;
		std::vector<DivRow>		rows;
	};

	// 用于将日志转成html格式，方便查看
	class HtmlLog
	{
	public:
		void SetTitle(const std::string &title);

		void BeginLog();

		void EndLog();

		void AddDiv(const HtmlDiv &div);

		// 添加大标题
		void AddBigTitle(const std::string &title);

	private:
		static std::string GetHtmlStart(const char* title);

	public:
		static HtmlLog instance;

	public:
		std::string		m_htmlTitle;
		HtmlDiv			m_newDiv;
	};
}

#endif // _html_log_h_