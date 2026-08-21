#include "QtHoverButton.h"

QtHoverButton::QtHoverButton(QWidget* parent): QPushButton(QLatin1String(""), parent)
{
	setAttribute(Qt::WA_LayoutUsesWidgetRect);	  // fixes layouting on Mac
	setMouseTracking(true);
}

void QtHoverButton::enterEvent(QEnterEvent * /*event*/)
{
	if (isEnabled())
	{
		Q_EMIT hoveredIn(this);
	}
}

void QtHoverButton::leaveEvent(QEvent*  /*event*/)
{
	if (isEnabled())
	{
		Q_EMIT hoveredOut(this);
	}
}
