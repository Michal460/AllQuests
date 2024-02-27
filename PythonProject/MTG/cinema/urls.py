from django.urls import path
from . import views

urlpatterns = [
    path('', views.events_catalog, name='events_catalog'),
    path('<int:event_id>/', views.event_detail, name='event_detail'),
]
