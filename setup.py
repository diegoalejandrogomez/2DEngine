from git import Repo
import os
import subprocess
import shutil
from sys import platform


class Dependency:
    def __init__(self, name, url, branch, use_configure):
        self.name = name
        self.url = url
        self.branch = branch
        self.use_configure = use_configure
    def install(self, path):
        self.dependency_path = os.path.join(path, self.name)
        os.mkdir(self.dependency_path)
        print("Installing " + self.name + " from: " + self.url + " at: " + self.dependency_path)
        repo = Repo.clone_from(
            self.url, self.dependency_path,
            branch=self.branch)
        #Get dependencies of the dependencies...
        dependency_retrieve_process = subprocess.Popen(['git', 'submodule', 'update', '--init'], cwd=self.dependency_path)
        dependency_retrieve_process.wait()
    def compile(self):
        self.build_path = os.path.join(self.dependency_path, "build")
        if os.path.exists(self.build_path):
            #nuke it, I'll make my own build
            shutil.rmtree(self.build_path)
        os.mkdir(self.build_path)
        if not self.use_configure:
            cmake_process = subprocess.Popen(['cmake', '..'], cwd=self.build_path)
            cmake_process.wait()
        else:
            configure_process = subprocess.Popen(['../configure'], cwd=self.build_path)
            configure_process.wait()
        make_process = subprocess.Popen(['make'], cwd=self.build_path)
        make_process.wait()



class Installer:
    def __init__(self):
        self.dependencies = []
        self.third_party_directory = os.path.join(os.getcwd(), "ThirdParty")
        if os.path.exists(self.third_party_directory):
            #nuke it
            shutil.rmtree(self.third_party_directory)
        os.mkdir(self.third_party_directory)

    def add_dependency(self, name, url, branch, use_configure):
        dependency = Dependency(name, url, branch, use_configure)
        self.dependencies.append(dependency)
    
    def install_dependencies(self):
        for dependency in self.dependencies:
            dependency.install(self.third_party_directory)
            dependency.compile()

class EngineBuilder():
    def __init__(self):
        self.build_path = os.path.join(os.getcwd(), "build")
    
    def compile(self):
        if os.path.exists(self.build_path):
            #nuke it
            shutil.rmtree(self.build_path)
        os.mkdir(self.build_path)
        if platform == "darwin":
            cmake_process = subprocess.Popen(['cmake', '-G', 'Xcode', '..'], cwd=self.build_path)
            cmake_process.wait()
        else:
            cmake_process = subprocess.Popen(['cmake', '..'], cwd=self.build_path)
            cmake_process.wait()
            make_process = subprocess.Popen(['make'], cwd=self.build_path)
            make_process.wait()
    def execute(self):
        if platform == "darwin":
            engine = subprocess.Popen(['open', 'GameEngine.xcodeproj'], cwd=self.build_path)
            engine.wait()
#installer = Installer();
engine_builder = EngineBuilder();

#installer.add_dependency('wxWidgets', 'https://github.com/wxWidgets/wxWidgets.git', '3.2.2-hotfix', True)
#installer.add_dependency('SFML', 'https://github.com/SFML/SFML.git', '2.6.x', False)
#installer.install_dependencies()

engine_builder.compile()
engine_builder.execute()