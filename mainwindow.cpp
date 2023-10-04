#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QPrinter printer;
    //QString pname = QPrinterInfo::defaultPrinter().printerName();
    //QPrinter printer(QPrinterInfo::printerInfo("Zijiang-ZJ-58"));
    //printer.setPrinterName(pname);
    //QPrintDialog dialog(&printer, this);
    //dialog.accept();
    //ui->textEdit->print(&printer);
    // qDebug()<<printer.printerName();
    //QPrinterInfo printerInfo;


    //    QPrinter *printer = printerInfo.isNull() ? new QPrinter(QPrinter::HighResolution) : new QPrinter(printerInfo, QPrinter::HighResolution);
    //    qDebug() << "next show print dialog for printer" << printer->printerName();
    //    QPrintDialog printDlg(printer);
    //    qDebug() << "selected in print dialog" << printer->printerName() << ", but should be" << printerInfo.printerName();
    //    ui->textEdit->print(printer);
    //    QPainter painter(printer);
    //    painter.drawText(10,10,ui->textEdit->toPlainText());



    QString text =
            "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do\n"
            "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut\n"
            "enim ad minim veniam, quis nostrud exercitation ullamco laboris\n"
            "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor\n"
            "in reprehenderit in voluptate velit esse cillum dolore eu fugiat\n"
            "nulla pariatur. Excepteur sint occaecat cupidatat non proident,\n"
            "sunt in culpa qui officia deserunt mollit anim id est laborum.\n";

    QPrinter printer;

    //       QPrintDialog *dialog = new QPrintDialog(&printer);
    //       dialog->setWindowTitle("Print Document");

    //       if (dialog->exec() != QDialog::Accepted)
    //       {

    //       }

    printer.setPrinterName("Zijiang-ZJ-58");
    QPainter painter;
    painter.begin(&printer);

    painter.drawText(100, 100, 500, 500, Qt::AlignLeft|Qt::AlignTop, text);

    painter.end();

}

void MainWindow::on_pushButton_2_clicked()
{
    QPrinter printer;
    printer.setPrinterName("Zijiang-ZJ-58");
    QPrintDialog dialog(&printer, this);
    dialog.exec();
    //printer.setPaperSize(QPrinter::A4);
    ui->textEdit->print(&printer);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("/home/pi/file.pdf");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString html =
            "<div align=right>"
            "City, 11/11/2015"
            "</div>"
            "<div align=left>"
            "Sender Name<br>"
            "street 34/56A<br>"
            "121-43 city"
            "</div>"
            "<h1 align=center>DOCUMENT TITLE</h1>"
            "<p align=justify>"
            "document content document content document content document content document content document content document content document content document content document content "
            "document content document content document content document content document content document content document content document content document content document content "
            "</p>"
            "<div align=right>sincerly</div>";

    QTextDocument document;
    document.setHtml(html);

    /*QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("/home/pi/test.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);*/



    QPrinter printer;
    printer.setPrinterName("Zijiang-ZJ-58");
    QPrintDialog dialog(&printer, this);
    dialog.exec();
    document.print(&printer);
}

void MainWindow::on_pushButton_4_clicked()
{
    //QImage image = pdfPage->renderToImage(xres, yres, x, y, width, height);
    //image.save("convertedDocument.png");

    //QString file = QFileDialog::getSaveFileName(this, "Save as...", "name", "PNG (*.png);; BMP (*.bmp);;TIFF (*.tiff *.tif);; JPEG (*.jpg *.jpeg)");

    //ui->tableWidget->grab().save("/home/pi/image.jpg");

    //    QPrinter printer(QPrinter::PrinterResolution);
    //    printer.setOutputFormat(QPrinter::PdfFormat);
    //    //printer.setPaperSize(QPrinter::A8);
    //    //printer.setOrientation(QPrinter::Landscape);
    //    printer.setOutputFileName("/home/pi/test1.pdf");

    QPrinter printer;
    printer.setPrinterName("Zijiang-ZJ-58");

    //        QString pname = QPrinterInfo::defaultPrinter().printerName();
    //        qDebug()<<pname;
    //        QStringList pnames = QPrinterInfo::availablePrinterNames();
    //        for(int i=0;i<pnames.length();i++)
    //            qDebug()<<pnames[i]<<i;

    //QPrintDialog dialog(&printer, this);
    //dialog.accept();
    printer.setOrientation(QPrinter::Landscape);
    //printer.setPaperSize(QPrinter::A8);
    //printer.setPaperSize(QSizeF(2, 2), QPrinter::Inch);
    printer.setPaperSize(QSize(58, 74),QPrinter::Millimeter);
    //printer.setPageMargins(300, 300, 0, 0, QPrinter::Millimeter );
    //printer.setPageMargins(QMarginsF(2,2,2,2));
    //printer.setResolution(100);
    //printer.setOutputFileName("/home/pi/test1.pdf");




    QTextDocument doc;
    QFont font;
    font.setPointSize(5);
    font.setBold(QFont::DemiBold);
    font.setFamily("Calibri");
    font.setLetterSpacing(QFont::PercentageSpacing,100);
    doc.setDefaultFont(font);
    doc.setPageSize(printer.pageSizeMM());
    //doc.setTextWidth(2);
    //qDebug()<<printer.pageSizeMM()<<printer.pageSize()<<printer.pageRect()<<printer.pageRect().size();

    QString text("<head><style>table, th, td {border: 1px solid black; }</style></head><body><h1style='font-size:11px'>TSH</h1>");
    text.append("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        text.append("<th>").append(ui->tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        text.append("<tr>");
        for (int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (!item || item->text().isEmpty())
            {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(ui->tableWidget->item(i, j)->text()+" ").append("</td>");
            if(i!=ui->tableWidget->rowCount()-1)
            {
                //text.append("<hr>");
            }
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);


    doc.setPageSize(printer.pageRect().size());
    //doc.setPageSize(QSize(58, 65));
    //doc.setPageSize(printer.pageSizeMM());


    //doc.print(&printer);
    ui->tableWidget->render(&printer);
}

void MainWindow::on_pushButton_5_clicked()
{
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    QDateTime dt(QDateTime::currentDateTime());

    qDebug()<<cd<<ct<<cd.toString()<<ct.toString();
    qDebug() << dt.date().year() << dt.date().month() << dt.date().day() << dt.time().hour() << dt.time().minute() << dt.time().second();
    QString path="TSH "+dt.currentDateTime().toString();
    QFile file("/home/pi/"+path+".csv");
    //QFile file("/home/pi/123.csv");
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data( &file );
        QStringList strList;
        for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
        {
            strList <<

                       ui->tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString();
        }
        strList <<

                   ui->textEdit->toPlainText().toUtf8()
                   ;
        data << strList.join(";") << "\n";
        for( int r = 0; r < ui->tableWidget->rowCount(); ++r )
        {
            strList.clear();
            for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
            {   QTableWidgetItem* item = ui->tableWidget->item(r,c);        //Load items
                if (!item || item->text().isEmpty())                        //Test if there is something at item(r,c)
                {
                    ui->tableWidget->setItem(r,c,new QTableWidgetItem("0"));//IF there is nothing write 0
                }
                strList <<ui->tableWidget->item( r, c )->text();

            }
            data << strList.join( ";" )+"\n";
        }
        statusBar()->showMessage(tr("File saved successfully."), 3000);
        file.close();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, ("Open File"), NULL, ("csv File(*.csv)"));
    QString data;
    QFile importedCSV(fileName);
    QStringList rowOfData;
    QStringList rowData;
    data.clear();
    rowOfData.clear();
    rowData.clear();

    if (importedCSV.open(QFile::ReadOnly))
    {
        data = importedCSV.readAll();
        rowOfData = data.split("\n");           //Value on each row
        importedCSV.close();
    }

    for (int x = 0; x < rowOfData.size(); x++)  //rowOfData.size() gives the number of row
    {
        rowData = rowOfData.at(x).split(";");   //Number of collumn
        //int r=rowData.size();
        for (int y = 0; y < rowData.size(); y++)
        {
            ui->tableWidget->setItem(x,y,new QTableWidgetItem(rowData[y]));
        }
    }
    statusBar()->showMessage(tr("File successfully loaded."), 3000);
}

void MainWindow::on_pushButton_7_clicked()
{

    QMessageBox msgBox;

    msgBox.setWindowTitle("Warning...");
    msgBox.setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    msgBox.setText("Connect Waste Senor Plug Status and Click Yes to Resume. Click Cancel to Stop Washing.");

    msgBox.setStandardButtons(msgBox.Yes);
    msgBox.addButton(msgBox.Cancel);
    msgBox.setButtonText(msgBox.Yes, "Run");
    msgBox.setStyleSheet("QLabel{min-width:500 px; font-size: 24px;} QPushButton{ width:200px; height:50px; font-size: 18px; }");
    if(msgBox.exec()==msgBox.Yes)
        qDebug()<<"accepted";

    QDir dir("/home/pi/");
    QStringList filters;
    filters << "*.csv";
    for (const QFileInfo &file : dir.entryInfoList(filters,QDir::Files))
    {
        QListWidgetItem *item = new QListWidgetItem(file.fileName().left(file.fileName().indexOf(".")));
        qDebug()<<file.fileName()<<file.fileName().length()<<file.fileName().left(file.fileName().indexOf("."));
        item->setData(Qt::UserRole, file.absolutePath()); // if you need absolute path of the file
        ui->listWidget->addItem(item);
    }
    int n=ui->tableWidget->currentRow();
    qDebug()<<n;


}
