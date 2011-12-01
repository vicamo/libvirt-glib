/*
 * libvirt-gconfig-domain-input.c: libvirt domain input configuration
 *
 * Copyright (C) 2011 Red Hat
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 * Author: Christophe Fergeau <cfergeau@gmail.com>
 */

#if !defined(__LIBVIRT_GCONFIG_H__) && !defined(LIBVIRT_GCONFIG_BUILD)
#error "Only <libvirt-gconfig/libvirt-gconfig.h> can be included directly."
#endif

#ifndef __LIBVIRT_GCONFIG_DOMAIN_INPUT_H__
#define __LIBVIRT_GCONFIG_DOMAIN_INPUT_H__

G_BEGIN_DECLS

#define GVIR_TYPE_CONFIG_DOMAIN_INPUT            (gvir_config_domain_input_get_type ())
#define GVIR_CONFIG_DOMAIN_INPUT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GVIR_TYPE_CONFIG_DOMAIN_INPUT, GVirConfigDomainInput))
#define GVIR_CONFIG_DOMAIN_INPUT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GVIR_TYPE_CONFIG_DOMAIN_INPUT, GVirConfigDomainInputClass))
#define GVIR_IS_CONFIG_DOMAIN_INPUT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GVIR_TYPE_CONFIG_DOMAIN_INPUT))
#define GVIR_IS_CONFIG_DOMAIN_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GVIR_TYPE_CONFIG_DOMAIN_INPUT))
#define GVIR_CONFIG_DOMAIN_INPUT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GVIR_TYPE_CONFIG_DOMAIN_INPUT, GVirConfigDomainInputClass))

typedef struct _GVirConfigDomainInput GVirConfigDomainInput;
typedef struct _GVirConfigDomainInputPrivate GVirConfigDomainInputPrivate;
typedef struct _GVirConfigDomainInputClass GVirConfigDomainInputClass;

struct _GVirConfigDomainInput
{
    GVirConfigDomainDevice parent;

    GVirConfigDomainInputPrivate *priv;

    /* Do not add fields to this struct */
};

struct _GVirConfigDomainInputClass
{
    GVirConfigDomainDeviceClass parent_class;

    gpointer padding[20];
};

typedef enum {
    GVIR_CONFIG_DOMAIN_INPUT_DEVICE_MOUSE,
    GVIR_CONFIG_DOMAIN_INPUT_DEVICE_TABLET
} GVirConfigDomainInputDeviceType;

typedef enum {
    GVIR_CONFIG_DOMAIN_INPUT_BUS_PS2,
    GVIR_CONFIG_DOMAIN_INPUT_BUS_USB,
    GVIR_CONFIG_DOMAIN_INPUT_BUS_XEN
} GVirConfigDomainInputBus;

GType gvir_config_domain_input_get_type(void);

GVirConfigDomainInput *gvir_config_domain_input_new(void);
GVirConfigDomainInput *gvir_config_domain_input_new_from_xml(const gchar *xml,
                                                             GError **error);
void gvir_config_domain_input_set_device_type(GVirConfigDomainInput *input,
                                              GVirConfigDomainInputDeviceType type);
void gvir_config_domain_input_set_bus(GVirConfigDomainInput *input,
                                      GVirConfigDomainInputBus bus);

G_END_DECLS

#endif /* __LIBVIRT_GCONFIG_DOMAIN_INPUT_H__ */
