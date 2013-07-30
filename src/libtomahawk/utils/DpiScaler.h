/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2013, Teo Mrnjavac <teo@kde.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DPISCALER_H
#define DPISCALER_H

#include "DllMacro.h"

#include <QPaintDevice>
#include <QSize>

namespace TomahawkUtils
{

/**
 * @brief The DpiScaler class provides some convenience methods to recompute fixed pixel sizes
 * into values suitable for different environment DPI settings.
 * Usage:
 * class Foo : public QWidget, private TomahawkUtils::DpiScaler {...};
 */
class DLLEXPORT DpiScaler
{
public:
    DpiScaler( const QPaintDevice* that );

    QSize scaled( int w, int h ) const;
    QSize scaled( const QSize& size ) const;
    int scaledX( int x ) const;
    int scaledY( int y ) const;

    // convenience one-shot methods, usable without composing or private-inheriting DpiScaler
    static QSize scaled( const QPaintDevice* pd, int w, int h );
    static QSize scaled( const QPaintDevice* pd, const QSize& size );
    inline static int scaledX( const QPaintDevice* pd, int x );
    inline static int scaledY( const QPaintDevice* pd, int y );

private:
    inline static qreal ratioX( const QPaintDevice* pd );
    inline static qreal ratioY( const QPaintDevice* pd );
    inline static qreal getPpp();

    qreal m_ratioX;
    qreal m_ratioY;

    const QPaintDevice* that;

#ifdef Q_OS_MAC
    static const qreal s_baseDpi = 72.;
#else
    static const qreal s_baseDpi = 96.;
#endif
};

}

#endif // DPISCALER_H
