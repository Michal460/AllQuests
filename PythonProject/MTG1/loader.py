import json
import os

from main.models import Events

def load_data_to_db():
    json_dir = '/data'
    for filename in os.listdir(json_dir):
        if filename.endswith(".json"):
            with open(os.path.join(json_dir, filename), 'r') as file:
                event_data = json.load(file)
                event = Events(
                    title = event_data.get("Название"),
                    description = event_data.get("Описание"),
                    afisha = event_data.get("О фильме"),
                    author = event_data.get("Режиссёр"),
                    participants = event_data.get("В ролях"),
                    time = event_data.get("Время"),
                    city = event_data.get("Страна"),
                    year = event_data.get("Год производства"),
                    original_name = event_data.get("Оригинальное название")
                )
                event.save()