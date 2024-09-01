#pragma once

#include <qwidget.h>
#include <qlineedit.h>

class ReadlineLineEdit : public QLineEdit {
public:
    ReadlineLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {}

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_W) {
            handleCtrlW();
        } else if (event->modifiers() == Qt::AltModifier && event->key() == Qt::Key_D) {
            handleAltD();
        } else {
            QLineEdit::keyPressEvent(event);
        }
    }

private:
    void handleCtrlW() {
      this->cursorWordBackward(true);
      this->del();
    }
    void handleAltD() {
      this->cursorWordForward(true);
      this->del();
    }
};
