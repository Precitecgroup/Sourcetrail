#ifndef QT_SCREEN_SEARCH_BOX_H
#define QT_SCREEN_SEARCH_BOX_H

#include <QFrame>

#include "ControllerProxy.h"
#include "ScreenSearchController.h"

class QCheckBox;
class QHBoxLayout;
class QLineEdit;
class QPushButton;
class QtSelfRefreshIconButton;
class QTimer;


class QtFocusInFilter: public QObject
{
	Q_OBJECT

public:
	QtFocusInFilter(QObject* parent = Q_NULLPTR);

Q_SIGNALS:
	void focusIn();

protected:
	bool eventFilter(QObject* obj, QEvent* event) override;
};


class QtScreenSearchBox: public QFrame
{
	Q_OBJECT

public:
	QtScreenSearchBox(
		ControllerProxy<ScreenSearchController>* controllerProxy, QWidget* parent = nullptr);
	~QtScreenSearchBox() override;

	void setMatchCount(size_t matchCount);
	void setMatchIndex(size_t matchIndex);

	void addResponder(const std::string& name);

Q_SIGNALS:
	void closePressed();

public Q_SLOTS:
	void setFocus();

private Q_SLOTS:
	void searchQueryChanged();
	void findMatches();
	void returnPressed();

	void previousPressed();
	void nextPressed();

private:
	void activateMatch(bool next);

	void updateMatchLabel();

	ControllerProxy<ScreenSearchController>* m_controllerProxy;

	QLineEdit* m_searchBox;
	QPushButton* m_matchLabel;

	QtSelfRefreshIconButton* m_searchButton;
	QtSelfRefreshIconButton* m_prevButton;
	QtSelfRefreshIconButton* m_nextButton;
	QtSelfRefreshIconButton* m_closeButton;

	QHBoxLayout* m_checkboxLayout;
	std::map<std::string, QCheckBox*> m_checkBoxes;

	size_t m_matchCount = 0;
	size_t m_matchIndex = 0;

	QTimer* m_timer;
};

#endif	  // QT_SCREEN_SEARCH_BOX_H
