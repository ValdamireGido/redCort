#if !defined(__Engine_Std_Afx_h_include__) 
#define __Engine_Std_Afx_h_include__

#include "../redCort_config.h"
#include "RedCort.h"

#define ASSERT_PTR_VOID_RETURN(ptr)					\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return;										\
	}												\
} while (false)

#define ASSERT_PTR_INT_RETUR(ptr)					\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return -1;									\
	}												\
} while (false)

#define ASSERT_PTR_VK_RESULT_RETURN(ptr)			\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return VkResult::VK_INCOMPLETE;				\
	}												\
} while (false)

#define ASSERT_PTR_RC_RESULT_RETURN(ptr)			\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return redcort::Result::InvalidPointer;		\
	}												\
} while (false)

#endif // !defined(__Engine_Std_Afx_h_include__)
