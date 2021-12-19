# Standard
import os
from typing import List
from collections import namedtuple

# PySide
from PySide2.QtWidgets import QMainWindow, QFileDialog
from PySide2.QtCore import QFile, QSettings
from PySide2.QtUiTools import QUiLoader

# 3ds Max
from pymxs import runtime as rt
import qtmax

NodeInfo = namedtuple('NodeInfo', ['reference', 'name', 'materials'])

def get_nodes(selected: bool = False) -> List[NodeInfo]:
    nodes = []
    objects = list(rt.objects)

    if selected:
        objects = list(rt.GetCurrentSelection())

    for node in objects:
        info = NodeInfo(node, node.name, node.material)
        nodes.append(info)

    return nodes

def add_callback(name, method, id):
    rt.callbacks.addScript(rt.name(name), method, id=rt.name(id))

def remove_callback(name, id):
    rt.callbacks.removeScripts(rt.name(name), id=rt.name(id))

def str_to_bool(value):
    if not isinstance(value, str):
        raise TypeError(f'Value needs to be a string, got {{type(value)}}')

    if value.lower() == 'true':
        return True

    if value.lower() == 'false':
        return False

    raise ValueError(f'Value {{value}} could not be converted to bool.')

def rotate_pivot(obj, rotation):
    tempPosition = obj.position
    inverseRotation = rt.inverse(rt.quat(rotation))
    rt.setRefCoordSys(rt.Name('local'))
    obj.rotation = inverseRotation
    obj.objectoffsetrot = inverseRotation
    obj.objectoffsetpos *= inverseRotation
    obj.position = tempPosition

def export_model(model, filename: str, origin: bool = True, upAxis: str = 'Y'):
    rt.select(model)

    if origin:
        tempTransform = model.transform
        model.position = rt.Point3(0,0,0)
        model.rotation = rt.Point3(0,0,0)
        model.scale = rt.Point3(1,1,1)

    # if upAxis == 'Y':
    #     rotation = rt.eulerangles(90,0,0)
    #     rotate_pivot(model, rotation)
    # else:
    #     rotation = rt.eulerangles(0,0,0)
    #     rotate_pivot(model, rotation)

    rt.exportFile(filename, rt.name('noPrompt'), selectedOnly=True, using=rt.FBXEXP)

    if origin:
        model.transform = tempTransform

    rt.redrawViews()

class UnityExporter(QMainWindow):
    _modelQueue = []

    def __init__(self):
        if qtmax is not None:
            parent = qtmax.GetQMaxMainWindow()
        else:
            parent = None

        super().__init__(parent)
        self._parent = parent
        self.setup_settings()
        self.setup_ui()
        self.setup_connections()
        self.populate_models_list()
    
    def setup_settings(self):
        self._settings = QSettings('UnityExporter', 'UnityExporter')

    def setup_ui(self):
        """Sets up the initial UI, loading it from the .ui file.

        Raises:
            RuntimeError: If the .ui file is not readable or open in another application.
        """
        self.setWindowTitle('Unity Exporter')

        loader = QUiLoader()
        filename = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'unityexporter.ui')
        file = QFile(filename)
        if not file.open(QFile.ReadOnly):
            raise RuntimeError(f".ui {filename} file is not readable or open in another application.")
        self.ui = loader.load(file, self._parent)
        file.close()
        self.setCentralWidget(self.ui)

    def setup_connections(self):
        self.ui.exportSelected.toggled.connect(self.on_export_selected_checked)
        self.ui.exploreOutput.clicked.connect(self.on_explore_output_clicked)
        self.ui.exportModels.clicked.connect(self.export_models)

    def read_settings(self):
        if self._settings is None:
            return

        self.ui.upAxis.setCurrentIndex(self._settings.value('upAxis'))
        self.ui.moveToOrigin.setChecked(str_to_bool(self._settings.value('moveToOrigin')))
        self.ui.exportSelected.setChecked(str_to_bool(self._settings.value('exportSelected')))
        self.ui.filePath.setText(self._settings.value('outputPath'))

    def write_settings(self):
        if self._settings is None:
            return

        self._settings.setValue('upAxis', self.ui.upAxis.currentIndex())
        self._settings.setValue('moveToOrigin', self.ui.moveToOrigin.isChecked())
        self._settings.setValue('exportSelected', self.ui.exportSelected.isChecked())
        self._settings.setValue('outputPath', self.ui.filePath.text())

    def add_callbacks(self):
        add_callback('selectionSetChanged', self.populate_models_list, 'UnityExporter')

    def delete_callbacks(self):
        remove_callback('selectionSetChanged', 'UnityExporter')

    def on_explore_output_clicked(self):
        output = QFileDialog.getExistingDirectory(self, "Select output directory")
        self.ui.filePath.setText(output)

    def on_export_selected_checked(self, state):
        self.populate_models_list()

    def populate_models_list(self):
        self.ui.modelList.clear()
        self._modelQueue = []

        nodes = get_nodes(selected=self.ui.exportSelected.isChecked())
        for node in nodes:
            self.ui.modelList.addItem(node.name)
            self._modelQueue.append(node)

    def get_up_axis(self):
        upAxis = self.ui.upAxis.currentIndex()

        if upAxis == 0:
            return "Y"

        return "Z"

    def export_models(self):
        upAxis = self.get_up_axis()
        origin = self.ui.moveToOrigin.isChecked()
        path = self.ui.filePath.text()
        prefix = self.ui.filePrefix.text()

        for model in self._modelQueue:
            obj = model.reference
            name = model.name
            filename = os.path.join(path, prefix + name + ".fbx")
            export_model(obj, filename, origin=origin, upAxis=upAxis)

    # Override
    def showEvent(self, event):
        self.add_callbacks()
        self.read_settings()
        super().showEvent(event)

    # Override
    def closeEvent(self, event):
        self.delete_callbacks()
        self.write_settings()
        super().closeEvent(event)

def show_dialog():
    dialog = UnityExporter()
    dialog.show()

if __name__ == '__main__':
    show_dialog()