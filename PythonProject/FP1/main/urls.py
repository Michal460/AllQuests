from django.urls import path
from . import views

urlpatterns = [
    path('', views.events_catalog, name = 'index'),
    path('event/<int:event_id>/', views.event_detail, name = 'event_details'),
]