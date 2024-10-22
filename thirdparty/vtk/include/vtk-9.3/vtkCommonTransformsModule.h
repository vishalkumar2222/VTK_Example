
#ifndef VTKCOMMONTRANSFORMS_EXPORT_H
#define VTKCOMMONTRANSFORMS_EXPORT_H

#ifdef VTKCOMMONTRANSFORMS_STATIC_DEFINE
#  define VTKCOMMONTRANSFORMS_EXPORT
#  define VTKCOMMONTRANSFORMS_NO_EXPORT
#else
#  ifndef VTKCOMMONTRANSFORMS_EXPORT
#    ifdef CommonTransforms_EXPORTS
        /* We are building this library */
#      define VTKCOMMONTRANSFORMS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONTRANSFORMS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONTRANSFORMS_NO_EXPORT
#    define VTKCOMMONTRANSFORMS_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONTRANSFORMS_DEPRECATED
#  define VTKCOMMONTRANSFORMS_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKCOMMONTRANSFORMS_DEPRECATED_EXPORT
#  define VTKCOMMONTRANSFORMS_DEPRECATED_EXPORT VTKCOMMONTRANSFORMS_EXPORT VTKCOMMONTRANSFORMS_DEPRECATED
#endif

#ifndef VTKCOMMONTRANSFORMS_DEPRECATED_NO_EXPORT
#  define VTKCOMMONTRANSFORMS_DEPRECATED_NO_EXPORT VTKCOMMONTRANSFORMS_NO_EXPORT VTKCOMMONTRANSFORMS_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONTRANSFORMS_NO_DEPRECATED
#    define VTKCOMMONTRANSFORMS_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkCommonTransformsModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKCOMMONTRANSFORMS_EXPORT_H */