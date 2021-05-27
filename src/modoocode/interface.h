#pragma once
#include <cstdint>

enum class resolution : int32_t
{
	HD = 0,
	fullHD
};

enum class fps : uint32_t
{
	p30 = 0,
	p60
};

enum class rawformat : uint32_t
{
	yuyv = 0,
	yuv422,
	yuv444,
	yuv411
};

using convertKey = uint32_t;