from django.urls import path
from . import views

urlpatterns = [
    path('', views.events_catalog, name = 'cinema_list'),
    path('cinema/<int:event_id>/', views.event_detail, name = 'cinema_details'),
]