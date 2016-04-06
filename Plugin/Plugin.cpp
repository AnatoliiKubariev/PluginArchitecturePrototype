#include "Plugin.h"

#include <QtCore/QtPlugin>
#include <qmessagebox.h>


QStringList Plugin::Titles() const
  {
  return QStringList() << "FirstTitle" << "SecondTitle" << "ThirdTitle";
  }

void Plugin::GenerateMessage(const QString& action, QWidget* parent)
  {
  QAction some_action(parent);

  if(action == "FirstTitle")
    {
    QMessageBox::information(parent, "FirstTitle", "It`s First Message", "FirstButton");
    }
  else if(action == "SecondTitle")
    {
    QMessageBox::information(parent, "SecondTitle", "It`s Second Message", "SecondButton");
    }
  else if(action == "ThirdTitle")
    {
    QMessageBox::information(parent, "ThirdTitle", "It`s Third Message", "ThirdButton");
    }
  }