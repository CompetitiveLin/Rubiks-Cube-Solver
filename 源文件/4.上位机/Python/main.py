import form
import sys
from PyQt5 import QtCore, QtGui, QtWidgets

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    Form = QtWidgets.QWidget()
    ui = form.Ui_Form()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())
