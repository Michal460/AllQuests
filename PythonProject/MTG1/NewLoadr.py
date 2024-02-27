from django.db.models import Count

import json
import os
import django

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'MTG.settings')
django.setup()

from main.models import Events

check_arr = []
def load_data_to_db():
    json_dir = 'D:/PythonProject/data'
    for filename in os.listdir(json_dir):
        if filename.endswith(".json"):
            with open(os.path.join(json_dir, filename), 'r', encoding='utf-8') as file:
                event_data = json.load(file)
                if event_data['Название'] not in check_arr:
                    check_arr.append(event_data['Название'])
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
load_data_to_db()

Events.objects.filter(title="None inf").delete()
#
# duplicate_titles = Event.objects.values('title').annotate(count=Count('title')).filter(count__gt=1)
#
# for item in duplicate_titles:
#     Event.objects.filter(title=item['title']).delete()