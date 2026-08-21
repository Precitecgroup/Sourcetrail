#include "QtPushButton.h"

QtPushButton::QtPushButton() 
{
}

void QtPushButton::mouseDoubleClickEvent(QMouseEvent *event)
{
	QPushButton::mouseDoubleClickEvent(event);
	
	Q_EMIT doubleClicked();	
}
