#include "IoPlugin.h"

void IoPlugin::updateUI(Ui::MainWindow* ui) const{
	QMenu* ioMenu = new QMenu("Input/Output",ui->menuInsert);
	ui->menuInsert->addAction(ioMenu->menuAction());
	QAction* xAction= new QAction(QIcon(":/x.png"),"X");
	QAction* yAction= new QAction(QIcon(":/y.png"),"Y");
	QAction* ratioAction= new QAction("Ratio");
	QAction* outAction= new QAction(QIcon(":/output.png"),"Output");

	Workspace* ws=(Workspace*)ui->workspace->scene();
	connect(xAction,&QAction::triggered,ws,[=]{ws->addNode(Node::nodeMalloc("x"));});
	connect(yAction,&QAction::triggered,ws,[=]{ws->addNode(Node::nodeMalloc("y"));});
	connect(ratioAction,&QAction::triggered,ws,[=]{ws->addNode(Node::nodeMalloc("ratio"));});
	connect(outAction,&QAction::triggered,ws,[=]{ws->addNode(Node::nodeMalloc("out"));});

	ioMenu->addAction(xAction);
	ioMenu->addAction(yAction);
	ioMenu->addAction(ratioAction);
	ioMenu->addAction(outAction);

	ui->toolBox->addTool("x","X",QIcon(":/x.png"));
	ui->toolBox->addTool("y","Y",QIcon(":/y.png"));
	ui->toolBox->addTool("ratio","Width/Height");
	ui->toolBox->addTool("out","Output",QIcon(":/output.png"));
}

void IoPlugin::addNodes()const{
	Node::makeNodeMethods["x"] = &XNode::makeNode;
	Node::makeNodeMethods["y"] = &YNode::makeNode;
	Node::makeNodeMethods["ratio"]= &RatioNode::makeNode;
	Node::makeNodeMethods["out"]= &OutputNode::makeNode;
}
