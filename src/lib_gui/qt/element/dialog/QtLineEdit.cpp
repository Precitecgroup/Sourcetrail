#include "QtLineEdit.h"

QtLineEdit::QtLineEdit(QWidget* parent): QLineEdit(parent) {}

void QtLineEdit::focusInEvent(QFocusEvent* event)
{
	Q_EMIT focus();
	QLineEdit::focusInEvent(event);
}
