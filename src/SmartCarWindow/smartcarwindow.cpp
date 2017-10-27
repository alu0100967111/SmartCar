#include "smartcarwindow.h"
#include "ui_smartcarwindow.h"

SmartCarWindow::SmartCarWindow(const struct params &config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmartCarWindow),
    smart_car_layout(new QGridLayout)
{
    ui->setupUi(this); // Configura la ventana ANTES

    size_struct frame_size = GetFrameSize(config);

    InicializeWindow(config, frame_size);

    smart_car_board = new SmartCarBoard(config, frame_size); // Configuro el tablero segun config.
    InicializeLayout(config.row_number,config.col_number);

    ui->SmartCarWidget->setLayout(smart_car_layout);

    connect(ui->b1, SIGNAL(clicked()), this, SLOT(b1_clicked()));
}

SmartCarWindow::~SmartCarWindow()
{
    delete ui;
}

void SmartCarWindow::InicializeWindow(const struct params &config, const struct size_struct &frame_size)
{
    // Ajusto la Ventana SmartCarWindow.

        // 1. Para que no se pueda redimensionar.

    this -> setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    this -> showMaximized();
    this -> smart_car_layout -> setHorizontalSpacing(0);
    this -> smart_car_layout -> setVerticalSpacing(0);

        // 2. Añadimos el margen segun el tamaño de los frames.

            // 2.1 Cojo el ancho y el largo de la pantalla.

    QRect screen = QApplication::desktop() -> screenGeometry();
    int screen_height = screen.height(), screen_width = screen.width(); // Tamaños de pantalla ya ajustados.

            // 2.2 Calculamos los margenes arriba/abajo & izquierda/derecha.
    int top_bottom_margin = ( (screen_height - (frame_size.height * config.row_number)) / 2 );
    int left_right_margin = ( (screen_width - (frame_size.width * config.col_number)) / 2 );

            // 2.3 Añadimos los márgenes.
    this -> smart_car_layout -> setContentsMargins(left_right_margin, top_bottom_margin, left_right_margin, top_bottom_margin);

}

void SmartCarWindow::InicializeLayout(const int row, const int column)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            smart_car_layout->addWidget(smart_car_board->smart_car_board_[i][j],i,j); // TODO: Poner privado...
        }
    }
}

struct size_struct SmartCarWindow::GetFrameSize(const struct params &config)
{
    // Ajusto las celdas de SmartCarBoard

        // 1. Ver el mayor y ajustar segun formula el tamaño del cuadrado.

            // 1.1 Cojo el ancho y el largo de la pantalla

    QRect screen = QApplication::desktop() -> screenGeometry();
    int screen_height = screen.height() - 100, screen_width = screen.width(); // Tamaños de pantalla ya ajustados.

            //1.2 Configuo segun hmax = screen_height/max(nº filas, nº columnas);

    int frame_width, frame_height;

    if (config.row_number >= config.col_number) {
        frame_height = screen_height / config.row_number; // (-200) Por la barra de herramientas
        frame_width = frame_height;
    }
    else {
        frame_height = screen_height / config.col_number; // (-200) Por la barra de herramientas
        frame_width = frame_height;
    }

        // 2. Para que los cuadrados ocupen el máximo espacio dentro de lo posible. Mientras no llegue al tope crecemos 1 de lado.

    while ( (frame_height * config.row_number < screen_height) && (frame_height * config.col_number < screen_width) ) {
        frame_height++;
    }
    frame_width = frame_height;

        // 4. Le paso los tamaños de los cuadrados finales al Tablero (SmartCarBoard).
    return { frame_width, frame_height };
}

void SmartCarWindow::b1_clicked(){
    exit(1);

    //w.show();
    //return a.exec();
}
