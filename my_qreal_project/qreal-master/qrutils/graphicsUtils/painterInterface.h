#pragma once

#include <QtGui/QPainter>

#include "../utilsDeclSpec.h"

namespace graphicsUtils
{

class QRUTILS_EXPORT PainterInterface
{
public:
	PainterInterface();
	virtual void paint(QPainter *painter);
};

}
