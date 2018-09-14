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
	//ȷ�������ק.
	if (event->button() == Qt::LeftButton)
	{
		//�ȱ�����ק�����.
		m_dragPoint = event->pos();
		//��������ק����.
		m_dragItem = this->itemAt(event->pos());
	}
	//����ԭQListWidget���������������.
	QListWidget::mousePressEvent(event);
}

void MyListwidget::mouseMoveEvent(QMouseEvent * event)
{
	//ȷ����ס����ƶ�.
	if (event->buttons() & Qt::LeftButton)
	{
		QPoint temp = event->pos() - m_dragPoint;
		//ֻ��������ȴ���Ĭ�ϵľ���,�Żᱻϵͳ��Ϊ���γ���ק�Ĳ���.
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
	//���ö���Ϊ�ƶ�����.
	event->setDropAction(Qt::MoveAction);
	//Ȼ������¼�.���һ��Ҫд.
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
		QList<QUrl> urlList = data->urls();//��ȡurl�б�
		for (int i = 0; i < urlList.size(); ++i) {
			qDebug() << "Drag url = " << urlList.at(i);
			emit acceptUrl(urlList.at(i));
		}
	}
	else if (data->hasFormat("fileName")) {
		//��������ק����.
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
	//	//�ҵ���ǰ���λ���ڲ����е���.
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
