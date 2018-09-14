#include "MyListwidget.h"



MyListwidget::MyListwidget(QWidget* parent):
	QListWidget(parent)
{
	this->setAcceptDrops(true);
}


MyListwidget::~MyListwidget()
{
}

void MyListwidget::mousePressEvent(QMouseEvent * event)
{
	//确保左键拖拽.
	if (event->button() == Qt::LeftButton)
	{
		//先保存拖拽的起点.
		m_dragPoint = event->pos();
		//保留被拖拽的项.
		m_dragItem = this->itemAt(event->pos());
	}
	//保留原QListWidget部件的鼠标点击操作.
	QListWidget::mousePressEvent(event);
}

void MyListwidget::mouseMoveEvent(QMouseEvent * event)
{
	//确保按住左键移动.
	if (event->buttons() & Qt::LeftButton)
	{
		QPoint temp = event->pos() - m_dragPoint;
		//只有这个长度大于默认的距离,才会被系统认为是形成拖拽的操作.
		if (temp.manhattanLength() > QApplication::startDragDistance())
		{
			if (m_dragItem == NULL) return;
			QDrag *drag = new QDrag(this);
			QMimeData *mimeData = new QMimeData;
			mimeData->setData("fileName", m_dragItem->text().toUtf8());
			drag->setMimeData(mimeData);
			auto action = drag->exec(Qt::CopyAction | Qt::MoveAction);
		}
	}
}

void MyListwidget::dragEnterEvent(QDragEnterEvent * event)
{
	//设置动作为移动动作.
	event->setDropAction(Qt::MoveAction);
	//然后接受事件.这个一定要写.
	event->accept();
}

void MyListwidget::dragMoveEvent(QDragMoveEvent * event)
{
	event->setDropAction(Qt::MoveAction);
	event->accept();
}

void MyListwidget::dropEvent(QDropEvent * event)
{
	if (event->source() == this) {
		//qDebug() << "Draging self";
		return;
	}
	const QMimeData* data = event->mimeData();
	//qDebug() << "In drog Event";
	if (data->hasUrls()) {
		QList<QUrl> urlList = data->urls();//获取url列表
		for (int i = 0; i < urlList.size(); ++i) {
			qDebug() << "Drag url = " << urlList.at(i);
			emit acceptUrl(urlList.at(i));
		}
	}
	else if (data->hasFormat("fileName")) {
		//保留被拖拽的项.
		m_dragItem = this->itemAt(event->pos());

		if (m_dragItem == NULL) {
			QString fileName = QString::fromUtf8(data->data("fileName"));
			qDebug() << "Drag file = " << fileName;
			emit acceptFileName(fileName);
		}
		else {
			QString fileName = QString::fromUtf8(data->data("fileName"));
			qDebug() << "Drag file = " << fileName << " into " << m_dragItem->text();
			emit acceptFileName(fileName);
		}
	}


	//QString str = QString::fromUtf8(->data());
	//if (!str.isEmpty())
	//{
	//	//找到当前鼠标位置在部件中的项.
	//	auto item = this->itemAt(event->pos());
	//	//
	//	if (!item)
	//		this->addItem(str);
	//	else
	//		this->insertItem(this->row(item), str);

	//	event->setDropAction(Qt::MoveAction);
	//	event->accept();
	//}

}
