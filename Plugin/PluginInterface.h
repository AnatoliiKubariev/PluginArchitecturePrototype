#pragma once

#include <QObject>
#include <QStringList>
#include <QAction>


class PluginInterface
  {
  //virtual ~PluginInterface() {};
  public:
    virtual QStringList Titles() const = 0;
    virtual void GenerateMessage(const QString& action, QWidget* parent) = 0;
  };


QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(PluginInterface, "plugin.unique.identificator")
QT_END_NAMESPACE