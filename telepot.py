from telegram.ext import Updater, CommandHandler, DelayQueue
import sqlite3
import threading
import d3ll4

DelayQueue(queue=None, burst_limit=300, time_limit_ms=1000, exc_route=None, autostart=True, name=None)

conn = sqlite3.connect('telegram_turbocattolicesimoedicola.db')

#select * from users_allowed

def send_file(bot,update,chat_id,url_download):
    update.message.reply_text("science.pdf in arrivo")
    try:
        r = bot.sendDocument(chat_id, open('science.pdf', 'rb'))
    except:
        error_msg = """Limitazione telegram di invio file! File maggiori di 20M non possono essere inviati in chat direttamente! Invio url in corso per permettere il download esterno dall'app"""
        update.message.reply_text(error_msg)
        update.message.reply_text(url_download)

    print(r)

    return r

def insert_allowed_user(id_chat):
    sql = "insert into users_allowed values (?)"

    conn = sqlite3.connect('telegram_turbocattolicesimoedicola.db')
    cur = conn.cursor()

    print(sql)
    print(id_chat)

    cur.execute(sql,[id_chat])
    conn.commit()
    conn.close()
    print("done")


#update.message.from_user


def allow_user(bot,update):
    messaggio = update.message.text[10:]
    reply = "Password errata"

    print(messaggio)

    if (messaggio == "IndianDeveloper"):
        reply = "Ora sei un utente abilitato! Congratulazioni"
        update.message.reply_text(reply)
        insert_allowed_user(update.message.chat.id)
    else:
        update.message.reply_text(reply)

def hello(bot, update):

    chat_id = update.message.chat.id
    
    reply = "File in arrivo"
    url = "https://node.nova-labs.ch/warez/Giornali%20-%20Riviste/Riviste.PdS.Apr.2018/Spotters.Magazine.30.By.PdS.pdf"

    thread = threading.Thread(target=send_file, args=[bot,update,chat_id,url])
    thread.start()

    # reply = 'Hello ' + update.message.from_user.username
    update.message.reply_text(reply)

def add_book(bot, update):
    2


TOKEN="627369594:AAG-gw6FtNmO6PPgmnpiP8HKfRSyh-pRH1o"

updater = Updater(TOKEN)

updater.dispatcher.add_handler(CommandHandler('hello', hello))
updater.dispatcher.add_handler(CommandHandler('password', allow_user))
updater.dispatcher.add_handler(CommandHandler('aggiungi', add_book))

updater.start_polling()
updater.idle()