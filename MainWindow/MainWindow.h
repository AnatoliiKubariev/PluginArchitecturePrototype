#pragma once

#include <QtWidgets/QMainWindow>
#include <QDir>
#include "ui_MainWindow.h"

class MainWindow: public QMainWindow
  {
  Q_OBJECT

  public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    void DoSomething();

  private:
    void CreateMenus();
    void LoadPlugins();
    void PopulateMenus(QObject *plugin);

    QDir m_plugins_dir;
    QStringList m_plugin_file_names;

    Ui::MainWindowClass m_ui;
    QMenu* m_plugin_menu;
  };
