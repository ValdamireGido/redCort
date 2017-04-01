#if !defined(__RC_Assert_h_include__)
#define __RC_Assert_h_include__

#include <string>
#include <assert.h>

#include <cstdarg>

namespace redcort
{
	namespace 
	{
		template<typename _T>
		std::wstring AssertionProccesser(_T _arg)
		{
			return std::to_wstring(_arg);
		}

		template<typename _T, typename... _Args>
		std::wstring AssertionProccesser(_T _arg, _Args&&... _args)
		{
			std::wstring output = std::to_wstring(_arg);
			output += AssertionProccesser(_args...);
			return output;
		}
	}

	template<typename... _Args>
	void r_assert_impl(bool _check, 
					   const wchar_t* _file,
					   unsigned _line)
	{
		if(_check)
		{
			return;
		}

		_wassert("", _file, _line);
	}

	template<typename... _Args>
	void r_assert_impl(bool _check, 
					   const wchar_t* _file,
					   unsigned _line,
					   const char* _foramt, _Args&&... _args)
	{
		if(_check)
		{
			return;
		}

		std::wstring assertMessage = AssertionProccesser(_args...);
		_wassert(assertMessage.c_str(), _file, _line);
	}

	inline void r_assert_impl_c(bool _ckeck, 
								const wchar_t* _file, 
								unsigned _line, 
								const char* _format, ...)
	{
		static const int k_size = 2048;

		char messageBuffer[k_size];
		const char* mes = NULL;
		if(_format != NULL)
		{
			{
				va_list args;
				va_start(args, _format);
				vsnprintf(messageBuffer, k_size, _format, args);
				va_end(args);
			}
			mes = messageBuffer;
		}

		std::wstring wc(k_size, L'#');
		mbstowcs(&wc[0], messageBuffer, k_size);
		
		_wassert(wc.c_str(), _file, _line);
	}
}

#define RASSERT(expr) redcort::r_assert_impl_c(expr, _CRT_WIDE(__FILE__), (unsigned)(__LINE__), #expr)
#define RASSERT2(expr, format, ...) redcort::r_assert_impl_c(expr, _CRT_WIDE(__FILE__), (unsigned)(__LINE__),format, ##__VA_ARGS__)

#define DASSERT(expr) (void)( (!!(expr)) || ( _CrtDbgReport( _CRT_ASSERT, __FILE__, __LINE__, NULL, "" ), 0 ) )
#define DASSERT2(expr, format, ...) (void)( (!!(expr)) || ( _CrtDbgReport( _CRT_ASSERT, __FILE__, __LINE__, NULL, format, ##__VA_ARGS__ ), 0 ) )

namespace 
{
	void thisfunctionisjustfortest()
	{
		bool check = false;

		//RASSERT(check);

		RASSERT2(check, "test %d", (int)check);
	}
}

#endif // __RC_Assert_h_include__