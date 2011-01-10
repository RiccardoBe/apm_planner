#ifndef QGCTOOLWIDGET_H
#define QGCTOOLWIDGET_H

#include <QWidget>
#include <QAction>
#include <QMap>
#include <QVBoxLayout>
#include "QGCToolWidgetItem.h"

#include "UAS.h"

namespace Ui {
    class QGCToolWidget;
}

class QGCToolWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QGCToolWidget(const QString& title, QWidget *parent = 0);
    ~QGCToolWidget();

    /** @brief Factory method to instantiate all tool widgets */
    static QList<QGCToolWidget*> createWidgetsFromSettings(QWidget* parent);
    /** @Give the tool widget a reference to its action in the main menu */
    void setMainMenuAction(QAction* action);
    /** @brief All instances of this class */
    static QMap<QString, QGCToolWidget*>* instances();

public slots:
    void addUAS(UASInterface* uas);
    /** @brief Delete this widget */
    void deleteWidget();
    /** @brief Store all widgets of this type to QSettings */
    static void storeWidgetsToSettings();

signals:
    void titleChanged(QString);

protected:
    QAction* addParamAction;
    QAction* addButtonAction;
    QAction* setTitleAction;
    QAction* deleteAction;
    QVBoxLayout* toolLayout;
    UAS* mav;
    QAction* mainMenuAction;

    void contextMenuEvent(QContextMenuEvent* event);
    void createActions();
    QList<QGCToolWidgetItem* >* itemList();
    const QString getTitle();
    /** @brief Add an existing tool widget */
    void addToolWidget(QGCToolWidgetItem* widget);

protected slots:
    void addParam();
    void addAction();
    void setTitle();


private:
    Ui::QGCToolWidget *ui;
};

#endif // QGCTOOLWIDGET_H
