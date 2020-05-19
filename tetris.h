//游戏主体
#ifndef TETRIS_H
#define TETRIS_H

#define MAXX 10     //显示窗口的横向格数
#define MAXY 20     //显示窗口的竖向格数
#define NEXTMAXX 6  //“下一个”显示窗口的横向格数
#define NEXTMAXY 6  //“下一个”显示窗口的竖向格数
#define WIDTH 30    //单格的宽度
#define HEIGHT 30   //单格的高度
#define INTERVAL 4  //单格之间的间隔
#define COUNT 4     //每个方块的格数

#include <cstdlib>
#include <ctime>
#include <QObject>
#include "tcpclient.h"

class Tetris:public QObject
{
    Q_OBJECT
public:
    Tetris(QObject *parent=nullptr);

    void init();//初始化

    /*UI交互*/
    //游戏部分
    //输入
    void move_left();//左移
    void move_right();//右移
    void move_rotate();//旋转
    void move_down();//下落
    void use_item();//使用道具
    //输出
    int* get_my_ui();//我方游戏界面
    int* get_opponent_ui();//对方游戏界面
    int get_next_block();//下一个方块
    int get_item();//道具信息

    //联机部分
    void input_user_name(QString name);//输入用户名

    /*测试用*/
    void send_test_msg(QString msg);
signals:
    /*需要显示对应内容时发出信号*/
    void update_my_ui();//我方界面变化
    void update_opponent_ui();//对方界面变化
    void update_next_block();//下一个方块变化
    void opponent_use_item();//对方使用道具
    void game_over();//游戏结束
    /*在ui中设置对应的槽*/
private:
    void test_client();

    tcpClient *client;
    QString user_name;

    int game_matrix[25][15];//模拟矩阵
    int next_block_number;//下一个方块的编号
    int item[5];//道具信息
    QString opponent_game_matrix;//对方数据
    int score;//分数

};

//方块的结构体
struct Block
{
    int x[COUNT];   //方块单格的x坐标
    int y[COUNT];   //方块单格的y坐标
    int centerX;    //方块的中心x坐标
    int centerY;    //方块的中心y坐标
    int ID;         //方块的ID
}

#endif // TETRIS_H
