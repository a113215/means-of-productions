## QGraphics View Framework介绍：
- QGraphicsView类提供视口
- QGraphicsScene类提供场景
- QGraphicsItem提供图元

### 实现放缩

自定义QGraphicView类并Reimplemented其wheelEvent方法

```
//监控鼠标滚轮根据滚动程序设置缩放比例
void GraphicsView::wheelEvent(QWgeelEvent *event)
{
	int wheelValue = event->angleDelta().y();
	m_ratio = (double)wheelValue / (double)1200 + 1;
    scale(m_ratio,m_ratio);//缩放函数，参数表示缩放的倍数
}
```
### 声明Scene对象并与QGraphicsView进行绑定
```
//m_表示声明为类成员变量，意指注意不要在函数的栈上分配其内存，这样会导致场景内存提前释放，进而无法显示场景。
QGraphicScene m_scene;
void BandScene(QGraphicsView *view)
{
	view->setScene(m_scene);
}
```
在创建图元前，有必要了解框架中的坐标系统说明。
### 框架坐标说明

- View coordinates：左上角为(0,0)点，x轴向右为正，Y轴向下为正。mapToScene(),mapFromScene()可转换Scene和View之间的坐标点。
- Scene coordinates：遵循标准十字坐标系，是图元的顶层坐标，描述每一个顶层图元的位置(可以看成所有无父类图元的父类图元)。
- Item coordinates：遵循标准十字坐标系，在父级图元中图元的位置表示的是其图元中心点的位置。
相关变换函数有、mapToParent()、mapFromParent()、mapToItem()、mapFromItem()。
### 声明图元对象并将其添加到场景中
框架提供一些标准图元类：QGraphicsEllipseItem、QGraphicsLineItem、QGraphicsPathItem、QGraphicsPixmapitem、QGraphicsPolygonitem、QGraphicsRectitem、QGraphicsSimpleTextitem、QGraphicsTextitem；
在QGraphicsScene中也具有相同功能的便利函数：addEllipse() 、addLine() 、addPath() 、addPixmap() 、addPolygon、addRect()以及addText()；此外也提供QAbstractGraphicsShapeItem接口和QGraphicsItem类来提供绘制自定义图元功能。

```
QGraphicsEllipseItem m_item;
void SetEllipseItem(QGraphicsScene *scene)
{
	scene.setBackgroundBrush(QBrush("#172a4b"));
    QPen pen;
    pen.setColor(Qt::lightGray);
    pen.setWidth(0);
    m_item.setPen(pen);
    im_tem.setRect(0,1,20,20);
    scene.addItem(&m_item);
}
```
### 设置图元可拖拽
此操作针对场景内的图元，并只是在场景内拖动。
如果要实现拖动整个场景，只需设置视图中fragmode属性为ScrollHangDrag即可。
图元的可拖拽属性设置：

```
//将设置了此属性的图元加入场景后，即可实现其图元与子图元的拖拽功能，其中图元和其子图元为一个整体进行拖拽。
QGraphicsItem::setFlags(QGraphicsItem::ItemIsMovable);
//注意若要实现在场景大小固定的情况下图元拖拽始终在场景内，就需要Reimplement图元类中的Itemchange()函数并监听图元的位置。
```

### 实现拖拽入View中创建图元

实现思路，监听鼠标press事件，并设置拖拽数据；在View中监听dropevent事件，接收拖拽数据并创建图元。

1.重写 widget事件mousePressEvent,并设置拖拽时的数据传输。

2.重写QGraphicView中鼠标拖拽的事件DropEvent()事件。(SetAcceptDrop属性设为true)

```
void Widget::mousePressEvent(QMouseEvent *event)
{
	//实现拖动显示image
	QDrag *drag = new QDrag(this);
	QByteArray array;
	QPixmap image = QPixmap::fromImage();
	QDataStream stream(&array,QIODevice::WriteOnly);//可用于传递数据
	stream<< "数据1"<<"数据2";
	drag->setMimeData(QMimeData("text/plain",stream));
	drag->setPixmap(image);
	drag->exec(Qt::CopyAction | Qt::MoveAction,Qt::CopyAction);
}
void GraphicsView::dropEvent(QDropEvent *event)
{
	//拽入View后做的响应处理--创建图元
}
```

