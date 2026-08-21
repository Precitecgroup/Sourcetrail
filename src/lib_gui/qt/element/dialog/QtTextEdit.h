#ifndef QT_TEXT_EDIT_H
#define QT_TEXT_EDIT_H

#include <QTextBrowser>

class QtTextEdit: public QTextBrowser
{
	Q_OBJECT

public:
	QtTextEdit(QWidget* parent = nullptr);

	void setViewportMargins(int left, int top, int right, int bottom);

Q_SIGNALS:
	void focus();

protected:
	void focusInEvent(QFocusEvent* event) override;
};

#endif	  // QT_TEXT_EDIT_H
