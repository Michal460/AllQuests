import sqlite3 as sq

con = sq.connect("saper.db")#Чтобы открыть или создать бд файл
cur = con.cursor()#Взаимодействие с бд
cur.execute("""
""")x

con.close()#Закрыть бд файл