import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import formatdate
from email import encoders

def main():
    msg = MIMEMultipart()
    msg['From'] = "chocoholicsanon123@gmail.com"
    msg['To'] = "attardj2015@gmail.com"
    msg['Date'] = formatdate(localtime = True)
    msg['Subject'] = "Test Email"
    msg.attach(MIMEText("test body"))

    #create attachment
    part = MIMEBase('application', "octet-stream")
    part.set_payload(open("Report.xlsx", "rb").read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition', 'attachment; filename="Report.xlsx"')
    msg.attach(part)

    #Next, log in to the server
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.connect("smtp.gmail.com",587)
    server.ehlo()
    server.starttls()
    server.ehlo()
    server.login("chocoholicsanon123@gmail.com","Qwertyu12!")
    #Send the mail
    server.sendmail("chocoholicsanon123@gmail.com", "attardj2015@gmail.com", msg.as_string())
    server.quit()

if __name__ == "__main__":
    main()