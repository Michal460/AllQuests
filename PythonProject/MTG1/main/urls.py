from django.urls import path, include
from . import views

urlpatterns = [
    path('cinema/', include('cinema.urls'), name = 'cinema_list'),
    path('theatre/', include('theatre.urls'), name = 'theatre_list'),
    # Другие URL-адреса
]

# urlpatterns = [
#     path('', views.events_catalog, name = 'index'),
#     path('event/<int:event_id>/', views.event_detail, name = 'event_details'),
# ]