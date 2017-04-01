#if !defined(__Results_h_include__)
#define __Results_h_include__

namespace redcort
{
	enum class Result
	{
		Success					= 0, 
		Failed					= 1, 
		InvalidPointer			= 2, 

		UnsuportedDriver		= 3, 

		StreamReadingFailed		,
		FileCannotBeOpened		
	};
}

#endif // __Results_h_include__