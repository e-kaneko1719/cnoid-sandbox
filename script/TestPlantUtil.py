import os
import cnoid.Base

projectDir = "project"

def loadProject(worldProject, simulatorProjects, robotProject, perspective = "DoubleSceneViews"):
    directory = os.path.dirname(os.path.realpath(__file__))

    parentDir = os.path.abspath(os.path.join(directory, os.pardir))
    directory = os.path.join(parentDir, projectDir)

    pm = cnoid.Base.ProjectManager.instance
    pm.loadProject(os.path.join(directory, perspective + ".cnoid"))
    pm.loadProject(os.path.join(directory, worldProject + ".cnoid"))
    worldItem = cnoid.Base.Item.find("World")

    for project in simulatorProjects:
        pm.loadProject(os.path.join(directory, project + ".cnoid"), worldItem)

    pm.loadProject(os.path.join(directory, robotProject + ".cnoid"), worldItem)
    pm.setCurrentProjectName(worldProject + "-" + robotProject)
