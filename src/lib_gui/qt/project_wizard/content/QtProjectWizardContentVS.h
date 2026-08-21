#ifndef QT_PROJECT_WIZARD_CONTENT_VS_H
#define QT_PROJECT_WIZARD_CONTENT_VS_H

#include "QtProjectWizardContent.h"

class QtProjectWizardContentVS: public QtProjectWizardContent
{
	Q_OBJECT

public:
	QtProjectWizardContentVS(QtProjectWizardWindow* window);

	void populate(QGridLayout* layout, int& row) override;

private Q_SLOTS:
	static void handleVSCDBClicked();
};

#endif	  // QT_PROJECT_WIZARD_CONTENT_VS_H
