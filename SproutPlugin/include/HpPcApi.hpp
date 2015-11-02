#ifndef HPPC_API_H
#define HPPC_API_H

// Exception specification ignored by VS, but we use them to indicate to SWIG which methdos can
// throw exceptions so it can handle them properly.
#pragma warning( disable : 4290 )

// PcException has its symbols not exported using dllexport but some derived exceptions does.
// As PcException is abstract and has only pure-virtual methods this is not a problem.
// We need this because we can't expose the symbols for PcNotInstalledException.
#pragma warning( disable : 4275 )

/*
 * Check if the header is exporting or importing
 * the API.
 */
#if !defined HPPC_STATIC && defined HPPC_EXPORTS
    #define HPPC_API __declspec(dllexport)
#elif defined HPPC_STATIC
    #define HPPC_API
#else
    #define HPPC_API __declspec(dllimport)
#endif

#endif // HPPC_API_H
