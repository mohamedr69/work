#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fetch.h"
#include <QScrollArea>
#include <QWidget>
#include <QScrollBar>
#include <QString>
#include <memory>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , f(new Fetch)
    , l(new Location)
    , timer(new QTimer)
{



    //ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::Update);
    ui->setupUi(this);
    ui->cityLineEdit->setPlaceholderText("Enter city name to search");
    QFont font("Arial", 20); // Specify the font family and size
    font.setBold(true);
    ui->label_3->setFont(font);
    ui->pushButton_2->setStyleSheet("background-color: darkgray;");
    ui->label_4->setText("Loading....");
    ui->label_6->setText("Loading....");
    ui->label_4->setStyleSheet("background-color: transparent; color: white;");
    ui->label_5->setStyleSheet("background-color: transparent; color: white;");
    ui->label_6->setStyleSheet("background-color: transparent; color: white;");
    //city = l->getMyCity(ui);
    city = "giza";
    f->fetchWeather(ui,city,"NO");
    int interval = 10000;
    //timer->start(interval);
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
}


void MainWindow::Update(){
    //QString city = l->getMyCity(ui);
    f->fetchWeather(ui,city,"NO");
}
MainWindow::~MainWindow()
{
    for(auto &btn:buttons){
        delete btn;
    }
    delete f;
    delete l;
    delete timer;
    delete containerLayout;
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    //QString city = ui->cityLineEdit->text();
    f->fetchWeather(ui,city,"NO");

}

void MainWindow::on_actionCelsius_triggered()
{
    if( ui->actionCelsius->isChecked()){

    ui->actionFehrenheit->setChecked(false);
    }
    else{

        ui->actionCelsius->setChecked(true);

    }
    //QString city = l->getMyCity(ui);
    f->fetchWeather(ui,city,"NO");
    for(QPushButton* btn:buttons){

        QString buttonText = btn->text();
        QStringList lines = buttonText.split('\n');
        QString secondLine = lines[1];
        QString splited;
         if (secondLine.contains('F')||secondLine.contains('f')){
             for (int i = 0; i < secondLine.length(); ++i) {
                     QChar currentChar = secondLine.at(i); // Get the current character

                     if (currentChar.isDigit() || currentChar == '.') { // Check if the character is a digit
                         splited += currentChar; // Append the digit to the numberString
                     } else {
                         break; // Exit the loop if a non-digit character is encountered
                     }
               }

             double number = splited.toDouble();
              qDebug() << number;

              double temperatureFahrenheit = (number-32.0)* 5.0 / 9.0;
              QString fahrenheitString = QString::number(temperatureFahrenheit, 'f', 2); // Format to 2 decimal places
              QString newText = QString("%1\n%2°C\n%3").arg(lines[0]).arg(fahrenheitString).arg(lines[2]);
              btn->setText(newText);
         }



    }

}

void MainWindow::on_actionFehrenheit_triggered()
{
    if( ui->actionFehrenheit->isChecked()){
        ui->actionCelsius->setChecked(false);

    }else{
        ui->actionFehrenheit->setChecked(true);

    }
    //QString city = l->getMyCity(ui);
    f->fetchWeather(ui,city,"NO");
    for(QPushButton* btn:buttons){

        QString buttonText = btn->text();
        QStringList lines = buttonText.split('\n');
        QString secondLine = lines[1];
        QString splited;
        if (secondLine.contains('C')||secondLine.contains('c')){
            for (int i = 0; i < secondLine.length(); ++i) {
                    QChar currentChar = secondLine.at(i); // Get the current character

                    if (currentChar.isDigit() || currentChar == '.') { // Check if the character is a digit
                        splited += currentChar; // Append the digit to the numberString
                    } else {
                        break; // Exit the loop if a non-digit character is encountered
                    }
              }
            double number = splited.toDouble();
             qDebug() << number;
             double temperatureFahrenheit = number*9/5 + 32;
             QString fahrenheitString = QString::number(temperatureFahrenheit, 'f', 2); // Format to 2 decimal places
             QString newText = QString("%1\n%2°F\n%3").arg(lines[0]).arg(fahrenheitString).arg(lines[2]);
             btn->setText(newText);
        }



    }

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_7->setStyleSheet("");
    ui->label_7->setText("");
    ui->label_7->setAlignment(Qt::AlignCenter); // Center-align the label text
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->label->setText("");
    ui->cityLineEdit->setText("");

}

void MainWindow::on_pushButton_4_clicked()
{
    //qDebug() << "here";
    if(buttons.size() < 6){
        for(QPushButton* btn:buttons){
            if(btn->text() == (searchCity + "\n" + searchData)){
                return;
            }
        }
        QPushButton *button = new QPushButton(QString("Button %1").arg(buttons.size() + 1));
        QPushButton *innerButton = new QPushButton("-", button);
        innerButton->setStyleSheet("QPushButton { background-color: red; }");
        innerButton->setFixedSize(50, 30); // Width: 80, Height: 30
         button->setFixedHeight(100);
         button->setFixedWidth(150);

         connect(innerButton, &QPushButton::clicked, this, &MainWindow::innerButtonClicked);

         if(searchData.contains("Sunny")){
             button->setStyleSheet("QPushButton { background-image: url(:/img/images/sunny.jpg); background-color: transparent; color: black;}");
         }else{
             button->setStyleSheet("QPushButton { background-image: url(:/img/images/night.jpg); color:white;}");
         }
          qDebug()<<searchData;
         button->setText(searchCity + "\n" + searchData);


         int row = buttons.size() / 3; // Assuming 3 columns
         int col = buttons.size() % 3;


         buttons.append(button);



         ui->gridLayout_2->addWidget(button, row, col);

         ui->scrollAreaWidgetContents_2->adjustSize();

             // Ensure scroll bar is properly updated
         ui->scrollArea->ensureWidgetVisible(button);

             // Reset the scroll position to the top
         ui->scrollArea->verticalScrollBar()->setValue(0);
         ui->label_7->setStyleSheet("");
         ui->label_7->setText("");
         ui->label_7->setAlignment(Qt::AlignCenter); // Center-align the label text
         ui->pushButton_3->hide();
         ui->pushButton_4->hide();
         ui->label->setText("");
         ui->cityLineEdit->setText("");
    }else{
        ui->label->setText("You reached maximum please remove one");
        ui->label->setStyleSheet("color: red;");

    }

}
void MainWindow::innerButtonClicked()
{
    // Handle inner button click event
    QPushButton *senderButton = qobject_cast<QPushButton*>(sender());
    if(senderButton) {
        // Get the parent button (outer button)
        QPushButton *outerButton = qobject_cast<QPushButton*>(senderButton->parent());
        if(outerButton) {
            qDebug() << "Inner button clicked in button: " << outerButton->text();
            // Perform the desired operation, e.g., remove the outer button
            ui->gridLayout_2->removeWidget(outerButton);
            buttons.removeOne(outerButton);
            delete outerButton;
            ui->scrollAreaWidgetContents_2->adjustSize();
        }
    }
}
void MainWindow::on_pushButton_clicked()
{

    if(ui->cityLineEdit->text() == ""){
       ui->cityLineEdit->setText("");
    }else{
        QString city = ui->cityLineEdit->text();
        searchCity = city;
        searchData = f->fetchWeather(ui,city,"YES");
        qDebug() << "2" << searchData;
        ui->pushButton_3->show();
        ui->pushButton_4->show();

    }

}
void MainWindow::setSearchData(QString s){
searchData = s;

}
