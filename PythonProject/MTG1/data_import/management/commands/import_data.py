import json
from django.core.management.base import BaseCommand
from MTG.main.models import Event

class Command(BaseCommand):
    help = "Import data from JSON files"
    def handle(self, *args, **kwargs):
        file_paths = "D:/PythonProject/data/0cinema.json"
        with open(file_paths, 'r', encoding='utf-8') as file:
            data = json.load(file)
            obj = Event(
                title = data["Название"],
                afisha = data["Описание"],
                description = data["О фильме"],
                author = data["Режиссёр"],
                participants = data["В ролях"],
                time = ["Время"],
                city = ["Страна"],
                year = ["Год производства"],
                original_name = ["Оригинальное название"]
            )
