// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
#include <windows.h>



// TODO: 在此处引用程序需要的其他头文件
#ifdef DARKCPPMSG_EXPORTS
#define DARKCPPMSG_API __declspec(dllexport)
#else
#define DARKCPPMSG_API __declspec(dllimport)
#endif

#include <deque>

#include <boost/unordered_map.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/foreach.hpp>

#include "tcp/tcp.hpp"

#include "error_t.h"