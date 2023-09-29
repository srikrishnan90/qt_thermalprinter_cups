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
//    printer.setPaperSize(QPrinter::A8);
//    printer.setOrientation(QPrinter::Portrait);
//    printer.setOutputFileName("/home/pi/test1.pdf");

    QPrinter printer;
    printer.setPrinterName("Zijiang-ZJ-58");

    QPrintDialog dialog(&printer, this);
    dialog.exec();
    printer.setOrientation(QPrinter::Portrait);
    //printer.setPaperSize(QPrinter::A8);
    //printer.setPaperSize(QSizeF(2, 2), QPrinter::Inch);
    printer.setPaperSize(QSize(58, 65),QPrinter::Millimeter);
    //printer.setPageMargins(300, 300, 0, 0, QPrinter::Millimeter );
    printer.setPageMargins(QMarginsF(20,20,0,0));



    QTextDocument doc;
    QFont font;
            font.setPointSize(5);
            font.setBold(QFont::Bold);
            font.setFamily("Calibri");
            font.setLetterSpacing(QFont::PercentageSpacing,100);
            doc.setDefaultFont(font);
            doc.setPageSize(printer.pageSizeMM());


    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < ui->tableWidget->columnCount(); i++) {
        text.append("<th>").append(ui->tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (!item || item->text().isEmpty()) {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(ui->tableWidget->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);

}
