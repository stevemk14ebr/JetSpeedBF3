///////////////////////////////////////////////////////////////////////////////
// EASTL/assert.cpp
//
// Copyright (c) 2005, Electronic Arts. All rights reserved.
// Written and maintained by Paul Pedriana.
///////////////////////////////////////////////////////////////////////////////



#include "EASTL/internal/config.h"
#include "EASTL/string.h"
#include "EASTL/EABase/eabase.h"

#if defined(EA_PLATFORM_MICROSOFT)
    #pragma warning(push, 0)
    #if defined _MSC_VER
        #include <crtdbg.h>
    #endif
    #if defined(EA_PLATFORM_WINDOWS)
        #ifndef WIN32_LEAN_AND_MEAN
            #define WIN32_LEAN_AND_MEAN
        #endif
        #include <windows.h>
    #elif defined(EA_PLATFORM_XENON)
        #include <comdecl.h>
    #endif
    #pragma warning(pop)
#else
    #include <stdio.h>
#endif




namespace eastl
{

    /// gpAssertionFailureFunction
    ///
    /// Global assertion failure function pointer. Set by SetAssertionFailureFunction.
    ///
    EASTL_API EASTL_AssertionFailureFunction gpAssertionFailureFunction        = AssertionFailureFunctionDefault;
    EASTL_API void*                          gpAssertionFailureFunctionContext = NULL;



    /// SetAssertionFailureFunction
    ///
    /// Sets the function called when an assertion fails. If this function is not called
    /// by the user, a default function will be used. The user may supply a context parameter
    /// which will be passed back to the user in the function call. This is typically used
    /// to store a C++ 'this' pointer, though other things are possible.
    ///
    /// There is no thread safety here, so the user needs to externally make sure that
    /// this function is not called in a thread-unsafe way. The easiest way to do this is
    /// to just call this function once from the main thread on application startup.
    ///
    EASTL_API void SetAssertionFailureFunction(EASTL_AssertionFailureFunction pAssertionFailureFunction, void* pContext)
    {
        gpAssertionFailureFunction        = pAssertionFailureFunction;
        gpAssertionFailureFunctionContext = pContext;
    }



    /// AssertionFailureFunctionDefault
    ///
    EASTL_API void AssertionFailureFunctionDefault(const char* pExpression, void* /*pContext*/)
    {
#if defined(EA_DEBUG) || defined(_DEBUG)      
        // We cannot use puts() because it appends a newline.
        // We cannot use printf(pExpression) because pExpression might have formatting statements.
        #if defined(EA_PLATFORM_MICROSOFT)
            OutputDebugStringA(pExpression);
            (void)pExpression;
        #else
            printf("%s", pExpression); // Write the message to stdout, which happens to be the trace view for many console debug machines.
        #endif
#endif
        EASTL_DEBUG_BREAK();
    }


    /// AssertionFailure
    ///
    EASTL_API void AssertionFailure(const char* pExpression)
    {
        if(gpAssertionFailureFunction)
            gpAssertionFailureFunction(pExpression, gpAssertionFailureFunctionContext);
    }


} // namespace eastl  