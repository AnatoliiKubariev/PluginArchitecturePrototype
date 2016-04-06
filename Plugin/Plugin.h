#pragma once

#include <QObject>
#include <QStringList>
#include <QAction>
#include "PluginInterface.h"
//#include <QtDesigner/QDesignerCustomWidgetInterface>

class Plugin: public QObject, public PluginInterface
  {
  Q_OBJECT
    Q_PLUGIN_METADATA(IID "plugin.unique.identificator" /*FILE "plugin.json"*/)
    Q_INTERFACES(PluginInterface)

  public:
    QStringList Titles() const Q_DECL_OVERRIDE;
    void GenerateMessage(const QString& action, QWidget* parent) Q_DECL_OVERRIDE;
  };
