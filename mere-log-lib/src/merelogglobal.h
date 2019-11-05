#ifndef MERELOGGLOBAL_H
#define MERELOGGLOBAL_H

#include <QtCore/QtGlobal>
#include <QDebug>

#if defined MERE_LOG_LIB
#define MERE_LOG_LIBSPEC Q_DECL_EXPORT
#else
#define MERE_LOG_LIBSPEC Q_DECL_IMPORT
#endif

#endif // MERELOGGLOBAL_H
