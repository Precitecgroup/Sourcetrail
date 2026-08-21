#include "QtWindowStack.h"

#include "QtWindow.h"


QtWindowStackElement::QtWindowStackElement(QWidget* parent)
	: QWidget(parent) 
{
}

QtWindowStack::QtWindowStack(QObject* parent)
	: QObject(parent) 
{
}

QtWindowStackElement* QtWindowStack::getTopWindow() const
{
	if (m_stack.size())
	{
		return m_stack.back();
	}

	return nullptr;
}

size_t QtWindowStack::getWindowCount() const
{
	return m_stack.size();
}

void QtWindowStack::pushWindow(QtWindowStackElement* window)
{
	if (m_stack.size())
	{
		m_stack.back()->hide();
	}

	window->show();

	m_stack.push_back(window);

	Q_EMIT push();
}

void QtWindowStack::popWindow()
{
	if (m_stack.size())
	{
		m_stack.back()->hide();
		m_stack.back()->deleteLater();
		m_stack.pop_back();

		Q_EMIT pop();
	}

	if (m_stack.size())
	{
		m_stack.back()->show();
	}
	else
	{
		Q_EMIT empty();
	}
}

void QtWindowStack::centerSubWindows()
{
	for (QtWindowStackElement* window: m_stack)
	{
		QtWindow* qtWindow = dynamic_cast<QtWindow*>(window);
		if (qtWindow)
		{
			if (qtWindow->isSubWindow())
			{
				qtWindow->moveToCenter();
			}
		}
	}
}

void QtWindowStack::clearWindows()
{
	for (QtWindowStackElement* window: m_stack)
	{
		window->hide();
		window->deleteLater();
	}

	m_stack.clear();

	Q_EMIT empty();
}
