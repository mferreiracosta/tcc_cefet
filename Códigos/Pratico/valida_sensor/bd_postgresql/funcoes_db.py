import psycopg2

class ConexaoDB:

    def __init__(self):
        self.con = psycopg2.connect(host='localhost',
                                    database='db_sinais',
                                    user='postgres',
                                    password='123456')

    def conecta_db(self):
        return self.con

    
