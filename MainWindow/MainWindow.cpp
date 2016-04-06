#include "MainWindow.h"

#include "PluginInterface.h"
#include <QPluginLoader>

MainWindow::~MainWindow()
  {

  }

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  {
  m_ui.setupUi(this);

  CreateMenus();
  LoadPlugins();
  }

void MainWindow::DoSomething()
  {
  QAction* action = qobject_cast<QAction *>(sender());
  PluginInterface* temp_plugin = qobject_cast<PluginInterface*>(action->parent());
  temp_plugin->GenerateMessage(action->text(), this);
  }

void MainWindow::CreateMenus()
  {
  connect(m_ui.actionClose, &QAction::triggered, this, [&]() { this->close(); });

  m_plugin_menu = menuBar()->addMenu("Plugin Menu");
  }

void MainWindow::LoadPlugins()
  {
  m_plugins_dir = QDir(qApp->applicationDirPath());
  m_plugins_dir.cdUp();
  m_plugins_dir.cdUp();
  m_plugins_dir.cd("plugins");
  for(auto file_name : m_plugins_dir.entryList(QDir::Files))
    {
    QPluginLoader loader(m_plugins_dir.absoluteFilePath(file_name));
    QObject *plugin = loader.instance();
    if(plugin)
      {
      PopulateMenus(plugin);
      m_plugin_file_names += file_name;
      }
    }

  }

void MainWindow::PopulateMenus(QObject* plugin)
  {
  PluginInterface* test_plugin = qobject_cast<PluginInterface*>(plugin);
  if(test_plugin)
    {
    for(auto& title : test_plugin->Titles())
      {
      QAction* action = new QAction(title, plugin);
      connect(action, &QAction::triggered, this, &MainWindow::DoSomething);
      m_plugin_menu->addAction(action);
      }
    }
  }
