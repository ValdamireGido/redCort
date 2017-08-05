#if !defined(__Engine_Std_Afx_h_include__) 
#define __Engine_Std_Afx_h_include__


/////////////////////////////////////////////////////


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


/////////////////////////////////////////////////////


#define ASSERT_PTR_NULL_VOID_RETURN(ptr)			\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return;										\
	}												\
} while (false)

#define ASSERT_PTR_NULL_INT_RETUR(ptr)				\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return -1;									\
	}												\
} while (false)

#define ASSERT_PTR_NULL_VK_RESULT_RETURN(ptr)		\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return VkResult::VK_INCOMPLETE;				\
	}												\
} while (false)

#define ASSERT_PTR_NULL_RC_RESULT_RETURN(ptr)		\
do { 												\
	if (ptr == nullptr)	{							\
		RASSERT(ptr);								\
		return redcort::Result::InvalidPointer;		\
	}												\
} while (false)


/////////////////////////////////////////////////////


#include "../redCort_config.h"

#include "RCAssert.h"
#include "Version.h"

#include "vulkan/vulkan.h"


/////////////////////////////////////////////////////


#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>


#if defined(G_DEBUG) && (ENABLE_DEBUG_STATEMENTS == 1)
	#define DEBUG_(statement) statement
#else 
	#define DEBUG_(statement)
#endif


#endif // !defined(__Engine_Std_Afx_h_include__)
