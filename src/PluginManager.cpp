#include "PluginManager.h"

#include <QDir>
#include <QPluginLoader>

PluginManager::PluginManager(Ui::MainWindow *mw):ui(mw){}

bool PluginManager::loadPlugins(){
	QDir dir(qApp->applicationDirPath());
	dir.cd("lib");
	bool success=false;
	for(const auto& fileName: dir.entryList(QDir::Files)){
		QPluginLoader pluginLoader(dir.absoluteFilePath(dir.absoluteFilePath(fileName)));
		if (auto plugin = pluginLoader.instance()){
			NodeInterface* interface= qobject_cast<NodeInterface *>(plugin);
			if (interface){
				interface->updateUI(ui);
				interface->addNodes();
				success= true;
				if(interface->redefineSaveLoad())
					plugins.push_back(interface);
			}
		}
	}
	return success;
}

void PluginManager::save(std::ostream &out)const{
	for(const auto& plugin: plugins)
		plugin->save(out);
}
void PluginManager::load(std::istream &in)const{
	for(const auto& plugin: plugins)
		plugin->load(in);
}
