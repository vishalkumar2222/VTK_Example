
#ifndef VTKCOMMONDATAMODEL_EXPORT_H
#define VTKCOMMONDATAMODEL_EXPORT_H

#ifdef VTKCOMMONDATAMODEL_STATIC_DEFINE
#  define VTKCOMMONDATAMODEL_EXPORT
#  define VTKCOMMONDATAMODEL_NO_EXPORT
#else
#  ifndef VTKCOMMONDATAMODEL_EXPORT
#    ifdef CommonDataModel_EXPORTS
        /* We are building this library */
#      define VTKCOMMONDATAMODEL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONDATAMODEL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONDATAMODEL_NO_EXPORT
#    define VTKCOMMONDATAMODEL_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONDATAMODEL_DEPRECATED
#  define VTKCOMMONDATAMODEL_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKCOMMONDATAMODEL_DEPRECATED_EXPORT
#  define VTKCOMMONDATAMODEL_DEPRECATED_EXPORT VTKCOMMONDATAMODEL_EXPORT VTKCOMMONDATAMODEL_DEPRECATED
#endif

#ifndef VTKCOMMONDATAMODEL_DEPRECATED_NO_EXPORT
#  define VTKCOMMONDATAMODEL_DEPRECATED_NO_EXPORT VTKCOMMONDATAMODEL_NO_EXPORT VTKCOMMONDATAMODEL_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONDATAMODEL_NO_DEPRECATED
#    define VTKCOMMONDATAMODEL_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkCommonDataModelModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKCOMMONDATAMODEL_EXPORT_H */
