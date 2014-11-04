#include <QDebug>
#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    m_xRot( 0 ),
    m_yRot( 0 ),
    m_zRot( 0 ),
    m_angle( 0 )
{
    this->setFocusPolicy( Qt::StrongFocus );
}

void Scene::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void Scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    // Set current drawing color to red
    //		   R	 G	   B
    glColor3f( 0.0f, 1.0f, 0.0f );

    // Draw a filled rectangle with current color
    //glRectf( -25.0f, 25.0f, 25.0f, -25.0f );

    glPushMatrix();
    {
        glRotatef( ( GLfloat ) m_angle,
                   ( GLfloat ) m_xRot,
                   ( GLfloat ) m_yRot,
                   ( GLfloat ) m_zRot );
        glRectf( -25.0f, 25.0f, 25.0f, -25.0f );
    }
    glPopMatrix();
}

void Scene::resizeGL( int w, int h )
{
    // Prevent a divide by zero
    if( h == 0 ) {
        h = 1;
    }

    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    GLfloat aspectRatio = ( GLfloat )w / ( GLfloat )h;
    if ( w <= h ) {
        glOrtho( -100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio,
                  1.0, -1.0);
    } else {
        glOrtho( -100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0,
                 1.0, -1.0 );
    }

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() ) {
        case Qt::Key_Right:
            m_angle -= 1;
            // Поворот вокруг оси Z вправо
            m_xRot = 0;
            m_yRot = 0;
            m_zRot = 1;
            break;
    }

    m_angle = m_angle % 360;

    updateGL();
}
