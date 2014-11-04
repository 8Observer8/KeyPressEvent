#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QKeyEvent>

class Scene : public QGLWidget
{
public:
    Scene( QWidget *parent = 0 );

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void keyPressEvent( QKeyEvent *event );

private:
    int m_xRot;
    int m_yRot;
    int m_zRot;
    int m_angle;
};

#endif // SCENE_H
